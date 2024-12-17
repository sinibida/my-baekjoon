template_dir := "./templates"
archive_dir := "./archive"

alias a := add
alias bj := add-bj
alias r := run
alias ac := archive

find_pattern := "find . -name \"*%s*\" -maxdepth 1"

# Create a problem folder from a template
add template name:
  cp -R {{template_dir}}/{{template}} ./{{name}}

# Create a BaekJoon problem folder from a template and a problem number
add-bj template code:
  cp -R {{template_dir}}/{{template}} ./bj-{{code}}
  echo "https://www.acmicpc.net/problem/{{code}}" >> ./bj-{{code}}/README.md

# Archive problem into './archive'
archive pattern:
  {{replace(find_pattern, "%s", pattern)}} | sort | head -1 | xargs -I dir mv dir {{archive_dir}}

# Run a problem
run pattern:
  {{replace(find_pattern, "%s", pattern)}} | xargs -I dir just -f dir/justfile

# Debug a problem
debug pattern:
  {{replace(find_pattern, "%s", pattern)}} | xargs -I dir just -f dir/justfile debug
