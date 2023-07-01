# python file to generate the json options for the question
import random, math, cmath, json

q_json_file = open("AAABB.json","w")     #  

def rr(mn, mx, st):
    return random.randrange(mn, mx, st)

def f2s(no,d):
    s1 = "{z:0."+str(d)+"f}"
    return s1.format(z=no)


def get_ckt_values():
     # given parameters for the question
     i= rr(1, 50, 1) # current
     a= (rr( 1, 20 ,1))/20 #area
     return [i,a]

q_json={}
q_json["values"]=[]

for x in range(100):
	 [i,a] = get_ckt_values()

	 q1cc = f2s(i/a,4)
	 q1wc1 = f2s(a/i,4)
	 q1wc2 = f2s((i*100)/a,4)
	 q1wc3 = f2s(i/(a*100),4)

	 q_json["values"].append([i,a,
                       q1cc, q1wc1, q1wc2, q1wc3])

q_json["parameters"]=["i","a", 
                       "q1cc","q1wc1","q1wc2","q1wc3"]

json.dump(q_json, q_json_file)
q_json_file.close()
