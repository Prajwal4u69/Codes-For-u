import numpy as np
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
import pandas as pd
data = pd.read_csv("C:/Users/Downloads/data2.csv")
X=data.iloc[:,:-1].values
Y=data.iloc[:,4].values
labelencoder=LabelEncoder()
X[:,0]=labelencoder.fit_transform(X[:,0])
print(X)
onehotencoder=OneHotEncoder(categorical_features=[0])
X=onehotencoder.fit_transform(X).toarray()
X_train,X_test,Y_train,Y_test=train_test_split(X,Y,test_size=1/3,random_state=0)
reg=LinearRegression()
reg.fit(X_train,Y_train)
pred=reg.predict(X_test)
