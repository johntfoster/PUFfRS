from sys import subprocess
sys.path.append( "/home/nelson/Downloads/App/PUFfRs/ext/breathe/" )
subprocess.call('cd .. ; doxygen', shell=True)
extensions = ['sphinx.ext.pngmath', 'sphinx.ext.todo', 'breathe' ]
breathe_projects = { "PUFfRs": "/home/nelson/Downloads/App/PUFfRs" }
breathe_default_project = "PUFfRs"
html_extra_path = ['../docs/html']
