import numpy as np
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
import pandas as pd
import statsmodels.formula.api as sm

data = pd.read_csv("C:/Users/GEU/Downloads/data2.csv")
X=data.iloc[:,:-1].values
Y=data.iloc[:,4].values
labelencoder=LabelEncoder()
X[:,0]=labelencoder.fit_transform(X[:,0])
onehotencoder=OneHotEncoder(categorical_features=[0])
X=onehotencoder.fit_transform(X).toarray()

X=np.append(np.ones([30,1]).astype(int),values=X,axis=1)
X_opt=X[:,[0,1,2,3,4,5,6]]
print(X_opt)
reg_ols=sm.OLS(endog=Y, exog=X_opt).fit()
print(reg_ols.summary())
X_train,X_test,Y_train,Y_test=train_test_split(X_opt,Y,test_size=1/3,random_state=0)
m=LinearRegression()
m.fit(X_train,Y_train)
print(m.score(X_test,Y_test))
