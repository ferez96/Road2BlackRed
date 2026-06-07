venv := if path_exists(".venv/bin/python") == "true" { ".venv/bin/python" } else { "python3" }
oeped := "OneEasyProblemEveryDay"

# show available recipes
default:
    @just --list

# run OEPED tests
test:
    {{ venv }} -m pytest {{ oeped }}/test_verify.py -v

# verify today's entry and update streak.json
verify:
    {{ venv }} {{ oeped }}/verify.py

# verify a specific date: just check 2026-06-07
check date:
    {{ venv }} {{ oeped }}/verify.py {{ date }}

# show current streak
streak:
    @cat {{ oeped }}/streak.json

# simulate GHA run with a given path: just simulate "OneEasyProblemEveryDay/2026-06-07/solution.go"
simulate path:
    CHANGED_PATHS="{{ path }}" {{ venv }} {{ oeped }}/verify.py --gha

# run verifier in GHA mode (reads CHANGED_PATHS from env)
gha:
    {{ venv }} {{ oeped }}/verify.py --gha

fmt:
    find . -name "*.go" -print0 | xargs -0 gofmt -w -s -l