import matplotlib.pyplot as plt
import pandas as pd
import os

allFiles = os.listdir("data")

allFiles.remove(".gitkeep")

allRewards = [x for x in allFiles if "Rewards" in x]
allOptimal = [x for x in allFiles if "Optimal" in x]

GaussianRewards = [x for x in allRewards if "Gaussian" in x]
BernoulliRewards = [x for x in allRewards if "Bernoulli" in x]

GaussianOptimal = [x for x in allOptimal if "Gaussian" in x]
BernoulliOptimal = [x for x in allOptimal if "Bernoulli" in x]

plotRewGauss = plt.figure(1)

for filename in GaussianRewards:
    
    algorithm = filename.split("_")[2]
    
    data = pd.read_csv("data/" + filename, header=None)
    
    meanData = data.mean(axis=0)

    plt.plot(meanData, label=algorithm)
    

plt.title("Average rewards obtained from a Gaussian distribution")
plt.xlabel("Time")
plt.ylabel("Average reward")

plt.grid()
plt.legend()

plt.savefig('docs/GaussianRewards.png')

plotOptGauss = plt.figure(2)

for filename in GaussianOptimal:
    
    algorithm = filename.split("_")[2]
    
    data = pd.read_csv("data/" + filename, header=None)
    
    meanData = data.mean(axis=0) * 100

    plt.plot(meanData, label=algorithm)
    

plt.title("Optimal choice made by the Bandit on a Gaussian distribution")
plt.xlabel("Time")
plt.ylabel("Optimal choice (%)")

plt.grid()
plt.legend()

plt.savefig('docs/GaussianOptimal.png')

plotRewBern  = plt.figure(3)

for filename in BernoulliRewards:
    
    algorithm = filename.split("_")[2]
    
    data = pd.read_csv("data/" + filename, header=None)
    
    meanData = data.mean(axis=0)

    plt.plot(meanData, label=algorithm)
    

plt.title("Average rewards obtained from a Bernoulli distribution")
plt.xlabel("Time")
plt.ylabel("Average reward")

plt.grid()
plt.legend()

plt.savefig('docs/BernoulliRewards.png')

plotOptBern  = plt.figure(4)

for filename in BernoulliOptimal:
    
    algorithm = filename.split("_")[2]
    
    data = pd.read_csv("data/" + filename, header=None)
    
    meanData = data.mean(axis=0) * 100

    plt.plot(meanData, label=algorithm)
    

plt.title("Optimal choice made by the Bandit on a Bernoulli distribution")
plt.xlabel("Time")
plt.ylabel("Optimal choice (%)")

plt.grid()
plt.legend()

plt.savefig('docs/BernoulliOptimal.png')

plt.show()

