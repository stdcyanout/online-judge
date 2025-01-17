import sys
import math

def main():
    v1, v2, theta_adj, beta_adj = map(float, sys.stdin.readline().split(','))
    theta = math.atan(v1)
    s = math.sqrt(v1 * v1 + 1)
    beta = math.atan(v2 / s)
    t = math.sqrt(v1 * v1 + v2 * v2 + 1)
    theta_new = theta + theta_adj
    beta_new = beta + beta_adj
    v2_new = t * math.sin(beta_new)
    s_new = t * math.cos(beta_new)
    v1_new = s_new * math.sin(theta_new)
    print("%.2f,%.2f,%.2f" % (t, v1_new, v2_new))

if __name__ == "__main__":
    main()