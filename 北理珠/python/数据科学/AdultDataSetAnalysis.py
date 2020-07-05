import pandas as pd
import sklearn
file = pd.read_table('http://archive.ics.uci.edu/ml/machine-learning-databases/adult/adult.data',encoding='utf-8',sep='',names=['age','workclass','fnlwgt','education','education-num','marital-status','occupation','relationship','race','sex','capital-gain','capital-loss','hours-per-week','native-country','income'])