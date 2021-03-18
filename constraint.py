import constraint

problem = constraint.Problem()

problem.addVariables("TDO", range(1, 10))
problem.addVariables("U", range(10))

def sum_constraint(t, d, o, u):
    if ((t*10 + o) + (d *10 + o)) == o*100 + u*10 + t:
        return True
problem.addConstraint(sum_constraint, "TDOU")

problem.addConstraint(constraint.AllDifferentConstraint())

solutions = problem.getSolutions()
print("Number of solutions found: {}\n".format(len(solutions)))

for s in solutions:
    print("T = {} O = {}, D = {}, U = {}"
        .format(s['T'], s['O'], s['D'], s['U']))
