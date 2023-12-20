FROM ubuntu:20.04


RUN apt-get update
RUN apt-get install xinetd -y
RUN DEBIAN_FRONTEND=noninteractive apt install -y lib32z1

ENV TERM xterm

RUN useradd -ms /bin/bash user

WORKDIR /home/bof3


ADD ./share /home/bof3

RUN echo "#!/bin/bash" > /home/bof3/run.sh && \
    echo "/home/bof3/bof3" >> /home/bof3/run.sh && \
    chmod +x /home/bof3/run.sh

RUN chown -R 750 /home/bof3

ADD ./settings/bof3.xinetd /etc/xinetd.d/bof3



CMD ["/usr/sbin/xinetd", "-dontfork"]

