# Usage guide

## Prequisites

- Just: a command runner
  - see: https://just.systems/man/en/introduction.html
- Environment to run a script in your favorite language.
  - e.g.: `g++` for C++

## Commands

Use `just -l/--list` for a brief summary of the available commands.

## Adding Templates

1. create directory with *template name* inside `./templates`
2. edit `justfile` like following.
```just
default:
  # add series of command to run under here.
  # learn more about justfile:
  #   https://just.systems/man/en/introduction.html
  g++ program.cpp -o bin
  cat in.txt | ./bin
```
3. setup your template accordingly. (see `templates/cpp` for example.)
4. run `just add <*template name*> <problem name>`!

# Contribution

## commit guide

`sys: ...`: System Development
`(No Prefix)`: problem solving!

# Related Documents

- KR) How to improve io speed in various languages: https://docs.google.com/document/d/17OUl9nU9i7vTkhk2q_qy4Q5Vl0HHE9bTLUHwbLp56WM/edit?tab=t.0#heading=h.mwvd9fqamd6
