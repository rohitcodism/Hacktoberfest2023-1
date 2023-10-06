# travelling salesman problem

import itertools

# Function to calculate the total distance of a tour
def calculate_total_distance(tour, distances):
    total_distance = 0
    for i in range(len(tour) - 1):
        total_distance += distances[tour[i]][tour[i + 1]]
    return total_distance + distances[tour[-1]][tour[0]]

# Function to solve the TSP using brute-force
def tsp_bruteforce(distances):
    num_cities = len(distances)
    cities = list(range(num_cities))
    shortest_tour = None
    shortest_distance = float('inf')

    for tour in itertools.permutations(cities):
        tour_distance = calculate_total_distance(tour, distances)
        if tour_distance < shortest_distance:
            shortest_distance = tour_distance
            shortest_tour = tour

    return shortest_tour, shortest_distance

# Example usage:
distances = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]

shortest_tour, shortest_distance = tsp_bruteforce(distances)
print("Shortest tour:", shortest_tour)
print("Shortest distance:", shortest_distance)
