import requests, threading, queue

IPQueue = queue.Queue()
_WORKER_THREAD_NUM = 3

class Workers(threading.Thread):

    def run(self):
        while not IPQueue.empty():
            ip = IPQueue.get()
            try:
                rsp = requests.head('http://' + ip, timeout=2).headers
                print(ip, rsp['CF-RAY'])
            except:
                pass


def main():
    global IPQueue
    with open('cloudflare_ip.txt', 'r') as f:
        for ip in f.read().splitlines():
            IPQueue.put(ip)

    threads = []
    for i in range(_WORKER_THREAD_NUM) :
        thread = Workers()
        thread.start()
        threads.append(thread)
    for thread in threads :
        thread.join()

if __name__ == '__main__':
    main()