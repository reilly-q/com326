# build option variables
bld = 0 # 0 = test; 1 = release
env = 0 # 0 = c++; 1 = c++ & sfml

# build location variables

varSrc0 = 'src'

varObj0 = 'bld/test/'
varTrg0 = 'bin/test/'

varObj1 = 'bld/release/'
varTrg1 = 'bin/release/'

tmp = ["main.cpp"]
src = []
trg = 'app'
libs = ['sfml-window', 'sfml-graphics', 'sfml-system']

# build environment variables

env0 = Environment(CCFLAGS = '-std=c++14 -pthread')
env1 = Environment(CCFLAGS = '-std=c++14 -pthread -Ilib/SFML-2.5.1/include')

# build option if statements

if bld == 0: # 0 = test
    VariantDir(varObj0, varSrc0, duplicate = 0) # set object and source folder
    trg = varTrg0 + trg # set target directory

elif bld == 1: # 1 = release
    VariantDir(varObj1, varSrc0, duplicate = 0) # set object and source folder
    trg = varTrg1 + trg # set target directory

# set all source files

for i in range(len(tmp)):
    src.append(varObj0 + tmp[i]) if bld == 0 else src.append(varObj1 + tmp[i])

src.append(Glob(varObj0 + 'studentModule/*.cpp')) if bld == 0 else src.append(Glob(varObj1 + 'studentModule/*.cpp'))
#src.append(Glob(varObj0 + 'arcade/*.cpp')) if bld == 0 else src.append(Glob(varObj1 + 'arcade/*.cpp'))

# more build option if statements

if env == 0: # 0 = c++
    env0.Program(target = trg, source = src) # create program without sfml
elif env == 1: # 1 = c++ & sfml
    env1.Program(target = trg, source = src, LIBS = libs, LIBPATH = libpath) # create program with sfml
