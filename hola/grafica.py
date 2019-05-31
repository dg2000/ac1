import numpy as np

import matplotlib.pyplot as plt





t = np.loadtxt("datos.txt")[:,0]
a = len(t)

x = np.loadtxt("datos.txt")[:,1]

y = np.loadtxt("datos.txt")[:,2]

x1 = np.loadtxt("datos.txt")[:,3]

y1 = np.loadtxt("datos.txt")[:,4]

T = np.loadtxt("datos.txt")[:a-1,5]


e = t[a-1]
m = x[a-1]
B = y[a-1]
Eo = x1[a-1]

px = m*x1
py = m*y1
r1 = (x*x + y*y)**0.5
r2 = ( (px*px + py*py)**0.5)/(e*B) 

print "la energia final fue de " +  str( (px[a-2]**2.0 + py[a-2]**2.0)/(2.0*m*e*1000000) ) + " MeV"
plt.figure()
plt.plot(x[:len(t)-1], y[:len(t)-1], color="blue", linewidth=0.3, linestyle="-")
plt.xlabel('x')
plt.ylabel('y')
plt.title('x vs y')
plt.savefig("x_vs_y.pdf")

plt.figure()
plt.plot(r1[:a-1], r2[:a-1], label='simulacion')
plt.plot(r1[:a-1], r1[:a-1], label='theory')
plt.xlabel('r1')
plt.ylabel('r2')
plt.title("r1 vs r2")
plt.savefig("radios.pdf")

plt.figure()
plt.plot(x[:a-1], x1[:a-1], color="blue", linewidth=0.3, linestyle="-")
plt.xlabel('x')
plt.ylabel('Vx')
plt.title('Vx vs x')
plt.savefig('vx_vs_x.pdf') 

plt.figure()
plt.plot(t[:a-1], e*B*r2[:a-1])
plt.xlabel('t')
plt.ylabel('p')
plt.title('p vs t')
plt.savefig("momentum.pdf")


plt.figure()
plt.plot(y[:a-1], y1[:a-1], color="blue", linewidth=0.3, linestyle="-")
plt.xlabel('y')
plt.ylabel('Vy')
plt.title('Vy vs y')
plt.savefig('vy_vs_y.pdf') 

plt.figure()
plt.plot(t[T.nonzero()], T[T.nonzero()])
plt.xlabel('t')
plt.ylabel('T')
plt.title("T vs t")
plt.savefig('T_vs_t.pdf')




