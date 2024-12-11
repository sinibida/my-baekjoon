template_dir := "./templates"

# Create a problem folder from a template
add template name:
  cp -R {{template_dir}}/{{template}} ./{{name}}

