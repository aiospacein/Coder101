$ErrorActionPreference = "Stop"

$VenvPath = Join-Path $PSScriptRoot "..\.venv"
$PythonExe = Join-Path $VenvPath "Scripts\python.exe"
$ZephyrDir = Join-Path $PSScriptRoot "..\zephyr"

Write-Host "=== Zephyr bootstrap ==="

# 1. Create venv if missing
if (-Not (Test-Path $PythonExe)) {
    Write-Host "Creating Python virtual environment..."
    python -m venv $VenvPath
}

# # 2. Upgrade pip
# Write-Host "Upgrading pip..."
# & $PythonExe -m pip install --upgrade pip

# # 3. Install west if missing
# $westInstalled = & $PythonExe - <<EOF
# import importlib.util
# print(importlib.util.find_spec("west") is not None)
# EOF

# if ($westInstalled -ne "True") {
#     Write-Host "Installing west..."
#     & $PythonExe -m pip install west
# }

# 4. Install Zephyr Python requirements
# Write-Host "Installing Zephyr requirements..."
# & $PythonExe -m pip install -r "$ZephyrDir\scripts\requirements.txt"

# 5. Build Zephyr
Write-Host "Building Zephyr application..."
Set-Location $ZephyrDir

& $PythonExe -m west build `
    -p auto `
    -b s32k3x4evb/s32k344 `
    samples/basic/blinky `
    -- `
    -DCMAKE_BUILD_TYPE=Debug

Write-Host "=== Zephyr build completed successfully ==="
