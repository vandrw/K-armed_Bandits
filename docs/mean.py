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


print("\nAverage Gaussian rewards:\n")
for filename in GaussianRewards:
    
    algorithm = filename.split("_")[2]
    
    data = pd.read_csv("data/" + filename, header=None)
    
    meanData = data.mean(axis=0)
    
    print(algorithm, ":  ", meanData[9900:10000].mean())
    

print("\nAverage optimal choice (Gaussian):\n")
for filename in GaussianOptimal:
    
    algorithm = filename.split("_")[2]
    
    data = pd.read_csv("data/" + filename, header=None)
    
    meanData = data.mean(axis=0) * 100

    print(algorithm, ":  ", meanData[9900:10000].mean())
    

print("\nAverage Bernoulli rewards:\n")
for filename in BernoulliRewards:
    
    algorithm = filename.split("_")[2]
    
    data = pd.read_csv("data/" + filename, header=None)
    
    meanData = data.mean(axis=0)
    
    print(algorithm, ":  ", meanData[9900:10000].mean())
    

print("\nAverage optimal choice (Bernoulli):\n")
for filename in BernoulliOptimal:
    
    algorithm = filename.split("_")[2]
    
    data = pd.read_csv("data/" + filename, header=None)
    
    meanData = data.mean(axis=0) * 100

    print(algorithm, ":  ", meanData[9900:10000].mean())