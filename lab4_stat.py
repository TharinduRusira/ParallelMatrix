import argparse
import re
import subprocess
import numpy as np


argparser = argparse.ArgumentParser()
argparser.add_argument('--run_command')
argparser.add_argument('--iterations', default=5)

class Executer():
    def __init__(self, args):
        self.n_iter = int(args.iterations)
        self.command = args.run_command
        
    def cmd_execute(self):
        p = subprocess.Popen(self.command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
        (out, err) = p.communicate()
        p.wait()
        return {'stdout':out,
                'stderr':err}
        
    def extract_run_time(self, output):
        m = re.search('Elapsed time = (\d+.\d+) miliseconds', output,flags = re.DOTALL)
        print m.group(1)
        time = float(m.group(1))
        return time
    
    def run_n_times(self):
        run_time = []
        for i in range(self.n_iter):
            output_result = self.cmd_execute()
            run_time.append(self.extract_run_time(output_result['stdout']+output_result['stderr']))
        
        average = sum(run_time) / self.n_iter;
        std = np.std(np.array(run_time))
        n = ((100*1.96*std)/(5*average))**2

        print "average: "+str(average)
        print "std: "+str(std)
        print "Number of iterations: "+str(n)


if __name__ == '__main__':
    args = argparser.parse_args()
    executor = Executer(args)
    executor.run_n_times()
