#!/usr/bin/bash

while true; do
  echo "[$(date +%T)] Iteration $counter - Starting..."
  adb wait-for-device
  echo
  # Call first script
  echo "Start First"
  ./script1.sh
  echo "Done First"
  echo

  # Call second script
  echo "Start second"
  ./script2.sh
  echo "Done Second"
  echo
done
