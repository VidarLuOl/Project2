import numpy as np
import matplotlib.pyplot as plt


def read_file(filename):
    infile = open(filename, "r")

    N = []
    rho_max = []
    average = []

    for line in infile:
        n, r, avr = line.split()
        N.append(int(n))
        rho_max.append(float(r))
        average.append(float(avr))

    return np.array(N), np.array(rho_max), np.array(average)


for i in [10, 25, 50, 100, 200]:
    filename = "error-n-" + str(i)
    N, rho_max, average = read_file(filename)

    plt.plot(rho_max[0:-1], average[0:-1], label = "n = " + str(i))

plt.legend(loc="best")
plt.xlabel("rho_max", fontsize=15)
plt.ylabel("Average Relative Error", fontsize=15)
plt.title("Average Realtive Error", fontsize=25)
plt.grid()
plt.show()


for i in [10, 25, 50, 100, 200]:
    filename = "error-small-n-" + str(i)
    N, rho_max, average = read_file(filename)

#    plt.plot(rho_max, average, 'o')
    plt.plot(rho_max, average, label = "n = " + str(i))

plt.legend()
plt.xlabel("rho_max", fontsize=15)
plt.ylabel("Average Relative Error", fontsize=15)
plt.title("Average Realtive Error", fontsize=25)
plt.grid()
plt.show()

