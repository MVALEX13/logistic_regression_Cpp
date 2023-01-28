import numpy as np
import matplotlib.pyplot as plt

#including the function obtained from c++ code
from DecisionFunction import func

f = open('./Dataset.dat','r')

# ignoring the first line ( entete ), doing so by reading the first line
line = f.readline()

# reading all the lines of the file and removing the '\n' from the string, splitting the data with '\t'
lines = [(line.rstrip('\n')).split('\t') for line in f]

# closing file
f.close()

# creating empty matrix
points_y0 = np.empty((0,2), dtype = np.float32)
points_y1 = np.empty((0,2), dtype = np.float32)

# filling matrixes with file datas
for line in lines:
    row = np.array([ np.float32(line[0]), np.float32(line[1]) ])
    if line[2] == '0':
        points_y0 = np.append( points_y0, [row], axis=0 )             # axis = 0 pour indiquer qu'on ajoute une ligne
    else:
        points_y1 = np.append( points_y1, [row], axis=0 )

# plot dataset
plt.figure()
plt.plot(points_y0[:,0], points_y0[:,1],'or',label = "data whose y = 0")
plt.plot(points_y1[:,0], points_y1[:,1],'ob',label = "data whose y = 1")
plt.xlabel("x1")
plt.ylabel("x2")
plt.title("dataset")

# plot contour of the decision function
xlist = np.linspace(-10, 10, 100)
ylist = np.linspace(-10, 10, 100)
X, Y = np.meshgrid(xlist, ylist)
Z = func(X,Y)
CS = plt.contour(X,Y,Z,levels = [0.5])

# plot the value on the isocurve
plt.clabel(CS, inline = 1, fontsize = 10)

# display the plot
plt.legend()
plt.show(block = False)    
plt.pause(2)
plt.close()