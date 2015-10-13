DISCOTANGO
==========

**DISCO**ntinuous **T**oolkit for **A**quisition of **N**eighboring **G**lobal **O**ptimizations. (Don't worry, the acronym doesn't mean anything.)

We write code and we don't care who knows.

# Interface and Style

We're writing this to expose some cool algorithms to the general public who may wish to write programs in languages that aren't matlab. Hence, [GPL](GPL.md). We're using C because it's straightforward and interops with literally every language. The previous reasoning also explains why we prefer `void *` to any macro-based parameterized typing, or C++ templates.

To that end, while we appreciate the thoroughness with which libraries like [gsl](https://www.gnu.org/software/gsl/) are able to fine-tune their output, accepting 11 parameters as in [gsl_siman_solve](https://www.gnu.org/software/gsl/manual/html_node/Trivial-example.html) is a bit much. Like most other C libraries, DISCOTANGO exposes functions and structs. The interface is typically:

```c
int dsc_some_fun(double (*fitness_fun) (void *), other_args..., dsc_options);
```

As you can see above, DISCOTANGO prefers the `dsc` prefix for all non-static symbols. `other_args` depends upon the specific function called. *Note that `other_args` is not variadic, the ellipses are just for description*. `dsc_options` is a struct containing common parameters to function calls, including an RNG, and constructor/destructors for any data.

## External Libraries

Use as many as you want! Just put them in the [libs](libs/) directory and add them to the [Makefile](Makefile) (talk to Danny if you don't know how). Make sure the licenses aren't screwy.

# Hit List

## Optimization

In [opt](opt/). Take a good hard look at [gsl](https://www.gnu.org/software/gsl/), which has a lot of this already implemented and battle-tested.

Algorithms:

- [ ] simulated annealing [link](http://katrinaeg.com/simulated-annealing.html)
- [ ] simplex [link](http://www.zweigmedia.com/RealWorld/tutorialsf4/frames4_3.html)
- [ ] linear programming
- [ ] genetic programming [link](http://www.doc.ic.ac.uk/~nd/surprise_96/journal/vol1/hmw/article1.html)
- [ ] ...

## Search

In [search](search/).

Algorithms:

- [ ] Boyer-Moore
- [ ] Levenshtein fuzzy matching
- [ ] A* (lol)
- [ ] Union-Find
- [ ] ...

## CSP

In [csp](csp/).

Algorithms:

- [ ] [solvers](http://www.cs.toronto.edu/~fbacchus/Papers/liu.pdf)
- [ ] ...

## Hardware Operations

We wish 2 achieve massive speed 4 great good.

- [ ] Matrix ops: ALTAS & its variants
- [ ] Multi-CPU
- [ ] Multi-process/threads
- [ ] use GPU

Questions: how to add this in a generic way? Will we have to rewrite all our code in a haze of `#ifdef`s? Hopefully not.
