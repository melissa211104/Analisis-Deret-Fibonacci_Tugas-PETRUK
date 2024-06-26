import matplotlib.pyplot as plt

# Data
n_values = [10, 25, 30, 40, 50]
time_recursive_memo = [11, 20, 22, 31, 43]
time_dynamic_programming = [0, 0, 0, 0, 0]

# Plotting the data
plt.figure(figsize=(10, 6))
plt.plot(n_values, time_recursive_memo, label='Rekursif dengan Memoization', marker='o')
plt.plot(n_values, time_dynamic_programming, label='Dynamic Programming', marker='s')

# Adding titles and labels
plt.title('Perbandingan Waktu Eksekusi Algoritma Fibonacci')
plt.xlabel('Nilai n')
plt.ylabel('Waktu Eksekusi (microseconds)')
plt.legend()

# Display the plot
plt.grid(True)
plt.show()
