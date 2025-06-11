# Philosophers

This project is a simulation of the famous **Dining Philosophers Problem**, designed to deepen understanding of threads, mutexes, and concurrency issues like race conditions and deadlocks.

## 🔧 Compile and run

```bash
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
All parameters are integers (in milliseconds). The last argument is optional.

Example:
```bash
./philo 5 800 200 200
```

## Objectives
- Prevent data races using mutexes
- Avoid deadlocks
- Ensure no starvation
- Handle precise time management
- Implement clean thread creation and joining

## Concepts studied

### Threads
Each philosopher runs in a separate thread, allowing them to act in parallel. This simulates real-world concurrency, where actions can overlap and timing matters.

### Mutexes
Forks are protected by mutexes, ensuring mutual exclusion: a fork can only be used by one philosopher at a time. Mutexes are also used for other shared data like printing and death detection.

### Race Conditions
To avoid race conditions, access to shared variables (e.g. last meal time, number of meals, death flag) is always protected by mutexes.

### Deadlock
A deadlock could occur if every philosopher picks up their left fork and waits forever for the right one. This is avoided by:
- changing fork acquisition order for odd-indexed philosophers
- or limiting the number of concurrent eaters

### Starvation
To prevent starvation, the program monitors the time since each philosopher’s last meal. If a philosopher doesn’t eat in time, the simulation stops and reports their death.

### Time Management
Precise timing is essential. We use gettimeofday() for millisecond accuracy, and carefully tuned usleep() loops to simulate sleeping, eating, and checking death status.
