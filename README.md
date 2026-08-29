# engineering-economy-factors

A set of small C++ command-line solvers for the standard engineering economy
interest factors. I wrote these while taking Engineering Economy because looking
values up in the factor tables was slow, and interpolating between table rows for
rates and periods that were not listed was where most of my arithmetic mistakes
came from. Computing the factor directly avoids both problems.

Each file is a standalone program with its own `main()`. Pick the file for the
factor you need, compile it, and run it.

## What each file does

| File | Factors | Can solve for |
|---|---|---|
| `F-P Factor.cpp` | F/P, P/F | F, P, i, n |
| `P-A Factor.cpp` | P/A, A/P | P, A |
| `F-A Factor.cpp` | F/A, A/F | F, A |
| `P-G Factor.cpp` | P/G | P, G |
| `A-G Factor.cpp` | A/G | A, G |
| `Compound Interest.cpp` | Compound amount | C, P, i, n |

Symbols follow the usual convention: P present worth, F future worth,
A uniform annual series, G arithmetic gradient, i interest rate per period,
n number of periods.

## Input convention

**Interest rate is entered as a decimal, not a percentage.** Enter `0.08` for 8%.
Every program prompts for this explicitly and echoes the rate back in both forms
so a mistake is visible in the output.

Programs that divide by `i` stop with an error message when `i` is 0 rather than
printing `inf` or `nan`. Several of those factors do have finite limits at i = 0
(A/P becomes P/n, for example), but the programs do not assume that is what you
meant.

## Building and running

Any C++ compiler works. With g++:

```bash
g++ -o pa "P-A Factor.cpp"
./pa
```

Filenames contain spaces, so quote them.

## Worked check

To confirm the P/G solver against a factor table, use i = 10%, n = 5, where the
tabulated P/G factor is 6.8618:

```
$ g++ -o pg "P-G Factor.cpp" && ./pg
Which variable do you want to find? (P or G): P
Enter Gradient (G): 100
Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: 0.10
Enter number of periods (n): 5
Present Worth (P) = 686.18
(P/G factor used = 6.8618 at i = 0.1 (10 %), n = 5)
```

Feeding 686.18 back in with `G` selected returns 100, which is the round-trip
check I use on the other files too.

## Scope and limits

- `P-A`, `F-A`, `P-G` and `A-G` solve only for the two worth values, not for
  `i` or `n`. Those inversions have no closed form and need a numerical root
  finder, which I have not written.
- No handling of geometric gradients, non-annual compounding periods, or
  continuous compounding.
- Output uses the default `double` formatting rather than fixed two-decimal
  currency formatting.
- These are coursework-era programs from January 2024. I have kept the original
  structure and style and limited later edits to correctness fixes.

## Correction history

The `G` branch of `P-G Factor.cpp` originally used an expression that was not the
algebraic inverse of the `P` branch, and returned values roughly 23% high at
i = 10%, n = 5. Both directions now share a single factor expression. The `G`
branch of `A-G Factor.cpp` also prompted for "Present Worth (P)" when it wanted
A; that label is corrected.
