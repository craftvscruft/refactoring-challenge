import subprocess
from subprocess import PIPE, STDOUT
import yaml
import pytest

with open("golden.yml", "r") as stream:
    cases = yaml.load(stream, yaml.FullLoader)

@pytest.mark.parametrize("input,output", [(case['input'], case['output']) for case in cases])
def test_inputs(input, output):
    exe_path = "../cmake-build-debug/03_obfuscated_lisp_interpreter_c"
    ris = subprocess.Popen([exe_path], stdin=PIPE, stdout=PIPE, stderr=PIPE)
    lines = input.split("\n")
    trimmed_lines = [line.strip() for line in lines]
    joined_lines = " ".join(trimmed_lines)
    ris.stdin.write((joined_lines.strip()).encode('utf-8'))
    ris.stdin.write(("\n").encode('utf-8'))
    # ris.stdin.write((trimmed_input + "\n").encode('utf-8'))
    ris.stdin.close()
    actual_output = ris.stdout.read().decode('utf-8')
    assert (output + "\n") == actual_output