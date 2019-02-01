import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
data=pd.read_csv("C:/Users/Downloads/tempData.csv")
X=data.iloc[:,0:1].values
Y=data.iloc[:,1].values
lin=LinearRegression()
lin.fit(X,Y)
poly=PolynomialFeatures(degree=4)
poly_x= poly.fit_transform(X)
poly.fit(poly_x,Y)
plt.scatter(X,Y,c='r')
plt.plot(X,lin.predict(X), color='b')
plt.xlabel("TEMP")
plt.ylabel("PRESSURE")
plt.show()
lin2=LinearRegression()
lin2.fit(poly_x,Y)
plt.scatter(X,Y,c='r')
plt.plot(X,lin2.predict(poly.fit_transform(X)),c='b')
plt.xlabel("TEMP")
plt.ylabel("PRESSURE")
plt.show()
print(lin.predict(110))
print(lin2.predict(poly.fit_transform(110)))
