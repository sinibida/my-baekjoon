template_dir := "./templates"
archive_dir := "./archive"

alias a := add
alias bj := add-bj
alias r := run
alias ac := archive

# Create a problem folder from a template
add template name:
  cp -R {{template_dir}}/{{template}} ./{{name}}

# Create a BaekJoon problem folder from a template and a problem number
add-bj template code:
  cp -R {{template_dir}}/{{template}} ./bj-{{code}}
  echo "https://www.acmicpc.net/problem/{{code}}" >> ./bj-{{code}}/README.md

# Archive problem into './archive'
archive pattern:
  find . -name "*{{pattern}}*" | sort | head -1 | xargs -I dir mv dir {{archive_dir}}

# Run a problem
run pattern:
  find . -name "*{{pattern}}*" | xargs -I dir just -f dir/justfile
