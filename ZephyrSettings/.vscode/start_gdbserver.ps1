# Kill any existing PEGDBServer
Get-Process pegdbserver_console -ErrorAction SilentlyContinue | Stop-Process -Force

# Small delay to ensure clean shutdown
Start-Sleep -Milliseconds 500

# Start PEGDBServer
Start-Process `
  "C:\PEMicro\PEDrivers\com.pemicro.debug.gdbjtag\win32\pegdbserver_console.exe" `
  -ArgumentList `
    "-startserver",
    "-device=NXP_S32K3xx_S32K344",
    "-interface=USBMULTILINK",
    "-port=USB1" `
  -WindowStyle Hidden

Write-Host "PEGDBServer started."
