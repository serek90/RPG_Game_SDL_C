#!/bin/bash

SERVICE="RPG_Game_SDL_C_run"
./$SERVICE &

sleep 20

if pgrep $SERVICE
then
  echo Everything ok
  pkill $SERVICE
else
  echo Program is not running
  exit 1
fi
