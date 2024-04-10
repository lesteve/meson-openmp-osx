project('my-test', 'c',
  version : '1.0.0',
  license : 'MIT')

openmp_dep = dependency('OpenMP', language: 'c', required: false)
# lib = library('my-test', 'my-test.c', dependencies: [openmp_dep])
executable('my-test', 'my-test.c', dependencies: [openmp_dep])
