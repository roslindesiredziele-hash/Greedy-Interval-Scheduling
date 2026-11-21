import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("./data/benchmark.csv")

# Runtime graph
plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["TimeMs"],
    marker="o",
    linewidth=2,
    markersize=6,
    color="royalblue"
)

plt.title(
    "Greedy Interval Scheduling Runtime"
)

plt.xlabel(
    "Number of Quests"
)

plt.ylabel(
    "Execution Time (ms)"
)

plt.grid(
    True,
    linestyle="--",
    alpha=0.6
)

plt.tight_layout()

plt.savefig(
    "./report/runtime_comparison.png",
    dpi=300
)

plt.close()

# Logarithmic graph
plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["TimeMs"],
    marker="o",
    linewidth=2,
    markersize=6,
    color="darkgreen"
)

plt.xscale("log")
plt.yscale("log")

plt.title(
    "Greedy Interval Scheduling Runtime (Log-Log Scale)"
)

plt.xlabel(
    "Number of Quests (log scale)"
)

plt.ylabel(
    "Execution Time (ms, log scale)"
)

plt.grid(
    True,
    which="both",
    linestyle="--",
    alpha=0.6
)

plt.tight_layout()

plt.savefig(
    "./report/runtime_logarithmic.png",
    dpi=300
)

plt.close()

print("Generated:")
print("  report/runtime_comparison.png")
print("  report/runtime_logarithmic.png")

plt.show()