import sys
import subprocess
sys.path.append( "/home/nelson/Downloads/App/PUFfRs/ext/breathe/" )
subprocess.call('cd ../..; doxygen', shell=True)
extensions = ['sphinx.ext.autodoc', 'sphinx.ext.coverage','breathe' ]
breathe_projects = { "PUFfRs": "/home/nelson/Downloads/App/PUFfRs" }
breathe_default_project = "PUFfRs"
html_extra_path = ['/home/nelson/Downloads/App/PUFfRs/docs/html']
