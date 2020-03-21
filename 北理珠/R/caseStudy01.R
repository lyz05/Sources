url_string<-"D:/git/lyz05/北理珠/R"
setwd(url_string)
#
#install.packages("VIM")
data(sleep,package = "VIM")
sleep
summary(sleep)
sleep[!complete.cases(sleep),]
mean(!complete.cases(sleep))
sum(is.na(sleep$span))
cleanedsleep<-na.omit(sleep)
cleanedsleep
#
#install.packages("xlsx")
library(xlsx)
write.xlsx(sleep,"sleep.xlsx",row.names=F,sheetName="Sheet 1")
write.xlsx(cleanedsleep,"cleanedsleep.xlsx",row.names=F,sheetName="sheet 1")
