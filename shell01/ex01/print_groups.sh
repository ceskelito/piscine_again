#!/bin/bash
groups $FT_USER | sed 's/^[^:]*:/ /' | sed 's/^ *//' | tr ' ' ','
