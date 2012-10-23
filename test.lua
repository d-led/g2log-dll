assert(require('alien'))
--g2log=alien.load("Debug/g2log")
g2log=alien.load("Release/g2log")
assert(g2log)

g2log.init_g2log:types('int','string','string')
print(g2log.init_g2log("1","."))

g2log.printf_g2log:types('void','string','int','string','string','string')
g2log.printf_g2log('1','2',3,'WARN','42')

for i=0,1000000 do
g2log.printf_g2log('1','2',33,'WARN','a log message')
end

g2log.stop_g2log:types('void')
g2log.stop_g2log()
