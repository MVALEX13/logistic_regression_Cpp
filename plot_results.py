import numpy as np
import matplotlib.pyplot as plt
import time
import matplotlib.animation as animation



## ---  HARVEST DATA FROM THE TXT FILE --- ##
#including the function obtained from c++ code
# from DecisionFunction import func

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








## --- PLOT CONTOURS FOR THE THETA OF EACH ITERATION --- ##
# plot contour of the decision functionf = open('./results.txt','r')

f = open('./results.txt','r')
line = f.readline()
line = line.rstrip('\n').split('\t') 

nb_it = int(line[4])

xlist = np.linspace(-10, 10, 100)
ylist = np.linspace(-10, 10, 100)
X1, X2 = np.meshgrid(xlist, ylist)

# creation d'un subplot en matlab ax et fig designent toutes les 2 la meme chose puisque une seule figure
fig = plt.figure()

# same than matlab subplots 
ax1 = fig.add_subplot(1,2,1)
ax2 = fig.add_subplot(1,2,2)

iter = 0
iter_vec = []
cost_vec = []
def animate(i):

    # pass 9 lines and read the 10th
    for i in range(10):
        line = f.readline()

    line = line.split('\t')
    theta0 = np.float32(line[0])
    theta1 = np.float32(line[1])
    theta2 = np.float32(line[2])
    cost =  np.float32(line[3])

    # declaration global mandatory to decalre the variabla as global
    global iter
    iter = iter + 10

    # plot data and model
    Z = theta0 + theta1*X1 + theta2*X2
    ax1.clear()
    ax1.plot(points_y0[:,0], points_y0[:,1],'or',label = "data whose y = 0")
    ax1.plot(points_y1[:,0], points_y1[:,1],'ob',label = "data whose y = 1")
    ax1.contour(X1,X2,Z,levels = [0.5])
    ax1.set_xlabel ("x1")
    ax1.set_ylabel("x2")
    ax1.set_title(f"iteration {iter}")
    ax1.legend()

    #plot cost function J
    global iter_vec
    global cost_vec
    iter_vec.append(iter)
    cost_vec.append(cost)
    ax2.clear()
    ax2.plot(iter_vec, cost_vec,'b')
    ax2.set_xlabel ("iteration")
    ax2.set_ylabel("J")
    ax2.set_title("cost function")

    

ani = animation.FuncAnimation(fig, animate, frames = round(nb_it/10) - 1, interval = 100, repeat = False)
plt.show(block = True)


f.close()
