venv := if path_exists(".venv/bin/python") == "true" { ".venv/bin/python" } else { "python3" }
oeped_dir := "OneEasyProblemEveryDay"

# show available recipes
default:
    @just --list

# run OEPED tests
test:
    {{ venv }} -m pytest {{ oeped_dir }}/test_oeped.py -v

# format all Go files
fmt:
    find . -name "*.go" -print0 | xargs -0 gofmt -w

# run an oeped.py subcommand: just oeped mkdir | just oeped run | just oeped record | just oeped record 2026-06-07 | just oeped gha | just oeped simulate <path>
oeped +args:
    {{ venv }} {{ oeped_dir }}/oeped.py {{ args }}
