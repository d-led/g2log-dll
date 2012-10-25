local OS=os.get()

local BOOST="/home/dled/src/boost_1_51_0/"

local cmd = {
 dir = { linux = "ls", windows = "dir" }
}

local Commands={}

for i,v in pairs(cmd) do
 Commands[i]=cmd[i][OS]
end

-- Apply to current "filter" (solution/project)
function DefaultConfig()
	location "Build"
	configuration "Debug"
		defines { "DEBUG", "_DEBUG" }
		objdir "Build/obj"
		targetdir "Build/Debug"
		flags { "Symbols" }
	configuration "Release"
		defines { "RELEASE" }
		objdir "Build/obj"
		targetdir "Build/Release"
		flags { "Optimize" }
	configuration "*" -- to reset configuration filter
end

function CompilerSpecificConfiguration()
	configuration {"xcode*" }
--		postbuildcommands {"$TARGET_BUILD_DIR/$TARGET_NAME"}

	configuration {"gmake"}
--		postbuildcommands  { "$(TARGET)" }
		buildoptions { "-std=gnu++11" }

	configuration {"codeblocks" }
--		postbuildcommands { "$(TARGET_OUTPUT_FILE)"}

	configuration { "vs*"}
--		postbuildcommands { "\"$(TargetPath)\"" }
end

----------------------------------------------------------------------------------------------------------------

-- A solution contains projects, and defines the available configurations
local sln=solution "g2log-dll"
	location "Build"
		sln.absbasedir=path.getabsolute(sln.basedir)
		configurations { "Debug", "Release" }
		platforms { "native" }
		libdirs {
			path.join(BOOST,"stage/lib")
		}
		includedirs {
			[[../src]],
			BOOST
		}
		vpaths {
			["Headers"] = {"**.h","**.hpp"},
			["Sources"] = {"**.c", "**.cpp"},
		}

----------------------------------------------------------------------------------------------------------------
   local dll=project "g2log"
   location "Build"
		kind "SharedLib"
		CompilerSpecificConfiguration()
		DefaultConfig()
		language "C++"
		files {
			"../src/active.h",
			"../src/active.cpp",
			"../src/crashhandler.h",
			"../src/crashhandler_unix.cpp",--todo configurable
			"../src/g2future.h",
			"../src/g2log.h",
			"../src/g2log.cpp",
			"../src/g2logworker.h",
			"../src/g2logworker.cpp",
			"../src/g2time.h",
			"../src/g2time.cpp",
			"../src/shared_queue.h",
			"g2log_dll.h",
			"g2log_dll.cpp"
		}
		if (OS=='linux') then links { "lua" }
		else  links { "lua5.1" } end

local simpletest=project "simpletest"
	local basedir="vs11test"
	kind "ConsoleApp"
	DefaultConfig()
	language "C++"
	files {
		path.join(basedir,"test.cpp")
	}
	uses {
		"g2log"
	}
	links {
		"g2log",
		"boost_timer",
		"boost_chrono",
		"boost_system",
		"boost_thread"
	}
--	CompilerSpecificConfiguration()
--	ConfigureGtestTuple()