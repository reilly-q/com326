# build option variables
bld = 0 # 0 = test; 1 = release
env = 0 # 0 = c++; 1 = c++ & sfml

# build location variables

varSrc0 = 'src'

varObj0 = 'bld/test/'
varTrg0 = 'bin/test/'

varObj1 = 'bld/release/'
varTrg1 = 'bin/release/'

src = ""
trg = 'app'
libs = ['sfml-window', 'sfml-graphics', 'sfml-system']
libpath = ['lib/SFML-2.5.1/lib']

# build environment variables

env0 = Environment(CCFLAGS = '-std=c++11 -pthread')
env1 = Environment(CCFLAGS = '-std=c++11 -pthread -Ilib/SFML-2.5.1/include')

# build option if statements

if bld == 0: # 0 = test
	VariantDir(varObj0, varSrc0, duplicate = 0) # set object and source folder
	trg = varTrg0 + trg # set target directory
	src = [varObj0 + 'main.cpp', Glob(varObj0 + 'warrior/*.cpp'), Glob(varObj0 + 'archer/*.cpp'), Glob(varObj0 + 'wizard/*.cpp'), Glob(varObj0 + 'weapon/*.cpp')] # set all source files
elif bld == 1: # 1 = release
	VariantDir(varObj1, varSrc0, duplicate = 0) # set object and source folder
	trg = varTrg1 + trg # set target directory
	src = [varObj1 + src[0]] # set all source files

if env == 0: # 0 = c++
    env0.Program(target = trg, source = src) # create program without sfml
elif env == 1: # 1 = c++ & sfml
    env1.Program(target = trg, source = src, LIBS = libs, LIBPATH = libpath) # create program with sfml
