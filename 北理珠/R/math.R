library(lattice)
data(iris)
parallel(~iris[1:4], iris, groups = Species,
         horizontal.axis = FALSE, scales = list(x = list(rot = 90)))
