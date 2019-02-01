import numpy as np
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
import pandas as pd
import statsmodels.formula.api as sm

data = pd.read_csv("C:/Users/Downloads/50_Startups.csv")
X=data.iloc[:,:-1].values
Y=data.iloc[:,4].values
labelencoder=LabelEncoder()
X[:,3]=labelencoder.fit_transform(X[:,3])
onehotencoder=OneHotEncoder(categorical_features=[3])
X=onehotencoder.fit_transform(X).toarray()
X1_train,X1_test,Y1_train,Y1_test=train_test_split(X,Y,test_size=1/3,random_state=0)
m2=LinearRegression()
m2.fit(X1_train,Y1_train)
print(m2.score(X1_test,Y1_test))
X=np.append(np.ones([50,1]).astype(int),values=X,axis=1)
X_opt=X[:,[0,1,2,3,4,5]]
print(X_opt)
reg_ols=sm.OLS(endog=Y, exog=X_opt).fit()
print(reg_ols.summary())
X_train,X_test,Y_train,Y_test=train_test_split(X_opt,Y,test_size=1/3,random_state=0)
m=LinearRegression()
m.fit(X_train,Y_train)
print(m.score(X_test,Y_test))
