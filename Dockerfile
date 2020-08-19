FROM gitpod/workspace-full
USER root
RUN apt-get update && apt-get install -y qemu-system-x86 \   
     && apt-get clean && rm -rf /var/cache/apt/* && rm -rf /var/lib/apt/lists/* && rm -rf /tmp/*
