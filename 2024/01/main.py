import pandas as pd

dataframe = pd.read_csv("input.csv", delim_whitespace=True, header=None)

sorted_df = dataframe.apply(lambda col: col.sort_values().reset_index(drop=True))

total_distance = 0
for index, row in sorted_df.iterrows():
    dist = abs(row.array[0] - row.array[1])
    total_distance += dist

print(f"Total distance: {total_distance}")

total_similarity = 0
for index_i, row_i in sorted_df.iterrows():
    similarity_count = 0
    for index_j, row_j in sorted_df.iterrows():
        if row_j.array[1] == row_i.array[0]:
            similarity_count += 1
    
    total_similarity += row_i.array[0] * similarity_count

print(f"Total similarity: {total_similarity}")

