get_bmi <- function(height, weight) {
   height <- height/100
   bmi <- weight / height**2
   return(bmi)
}
setwd('D:/git/lyz05/zhbit/R/myworkspace')
#install.packages("RODBC")
library(xlsx)
library(RODBC)
input <- read.table("BMItables.txt",header = TRUE)
input
input <- read.xlsx("BMItables.xlsx",sheetName = "BMI",header = TRUE,encoding = "UTF-8")
input
con<-odbcConnect("mysqlodbc64",uid="root",pwd="5137",DBMSencoding="utf-8")
data <- sqlFetch(con,"BMI")
data$BMI <- data$体重/((data$身高/100)**2)
data
close(con)
