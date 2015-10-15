DISCOTANGO
==========

**DISCO**ntinuous **T**oolkit for **A**quisition of **N**eighboring **G**lobal **O**ptimizations. (Don't worry, the acronym doesn't mean anything.)

# Interface and Style

We're writing this to expose some cool algorithms to the general public who may wish to write programs in languages that aren't matlab. Hence, [LGPL](LGPL.md). We're using C because it's straightforward and interops with literally every language. The previous reasoning also explains why we prefer `void *` to any macro-based parameterized typing, or C++ templates.

To that end, while we appreciate the thoroughness with which libraries like [gsl](https://www.gnu.org/software/gsl/) are able to fine-tune their output, accepting 11 parameters as in [gsl_siman_solve](https://www.gnu.org/software/gsl/manual/html_node/Trivial-example.html) is a bit much. Like most other C libraries, DISCOTANGO exposes functions and structs. The interface is typically:

```c
int disco_some_fun(disco_fitness_fun,
                   other_args...,
                   disco_options);
```

As you can see above, we use `under_scores`, and prefer the `disco` prefix for all non-static symbols. `disco_fitness_fun` is a typedef found in [typedefs.h](common/typedefs.h). `other_args` depends upon the specific function called. *Note that `other_args` is not variadic, the ellipses are just for description*. `disco_options` is a struct containing common parameters to function calls, including an RNG, and constructor/destructors for any data. All exported functions should return `int`, which will be `0` on success, and some standardized error code on failure.

Each exported function should be defined in its own `.c` and `.h` file. Naming should be `lowercase-with-hyphens`. The LGPL notice should be on top of all files; add your name to the `Copyright (c) 2015 <names>` line on any file you modify.

## External Libraries

Use as many as you want! Just put them in the [libs](libs/) directory and add them to the [Makefile](Makefile) (talk to Danny if you don't know how). Make sure the licenses aren't screwy.

## Testing

We need a unit test suite! We're not releasing any code without testing, and no algorithm is to be checked off below until tests are made and pass. There seem to be plenty of C unit test frameworks on the internet, but none of them seem any good. We'll need to figure this out when we start finishing off algorithms.

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
- [ ] A*
- [ ] Union-Find
- [ ] ...

## CSP

In [csp](csp/).

Algorithms:

- [ ] [solvers](http://www.cs.toronto.edu/~fbacchus/Papers/liu.pdf)
- [ ] ...

## Hardware Operations

We wish 2 achieve massive speed 4 great good.

- [ ] timeout or fixed iteration count
  - requires alg to keep some state somehow
- [ ] Matrix ops: ALTAS & its variants
- [ ] Multi-CPU
- [ ] Multi-process/threads
- [ ] use GPU

Questions: how to add this in a generic way? Will we have to rewrite all our code in a haze of `#ifdef`s? Hopefully not.
