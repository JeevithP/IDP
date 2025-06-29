import pandas as pd
import numpy as np

np.random.seed(42)
n = 1000
# Generate a wider range of sensor data
data = pd.DataFrame({
    'temperature': np.random.normal(30, 5, 1000),     # Mean 30, std 5
    'voltage': np.random.normal(3.5, 0.2, 1000),
    'current': np.random.normal(1.5, 0.4, 1000),
    'ambient_temp': np.random.normal(28, 3, 1000),
    'battery_charge': np.random.uniform(20, 100, 1000),
})

# Add labels: half of the values will be below threshold, half above
data['overheating'] = ((data['temperature'] > 28) | 
                       (data['voltage'] > 3.28) | 
                       (data['current'] > 1.8)).astype(int)

# Check label distribution
print(data['overheating'].value_counts())


data.to_csv("battery_data.csv", index=False)
print("Dataset saved as battery_data.csv")
