from datetime import datetime

time_format = "%Y-%m-%d %H:%M:%S"


def date_delta(start, end):
    start_time = datetime.strptime(start, time_format)
    end_time = datetime.strptime(end, time_format)
    ret_time = end_time - start_time
    return ret_time.total_seconds()


start = input()  # sys.stdin.readline()
end = input()  # sys.stdin.readline()

print(date_delta(start, end))
