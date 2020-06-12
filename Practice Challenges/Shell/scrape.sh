#! /bin/bash

host_id=$( echo $(</Users/christiansargusingh/Downloads/uuid.txt) | cut -c1-4 )
prefix="IRIS-"
echo "$prefix$host_id"
