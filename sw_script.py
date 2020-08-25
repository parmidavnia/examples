
import sys

#add packahe involving helper functions for graph helper functions parent
#code won't run without these helper functions

#inputList assumed as nested list of node inducetion variable and operand:
#for example:
# inputList = [[2,4,'phi],
# [4,16,'add'],
# [4,17,'add'],
# [4,18, 'add'],
# [5,1,'phi']]

def main(inputList):
    ReportedNodes = []
    Visited=[]
    SwAlgorithm(inputList, ReportedNodes, Visited , pOutputList)

#input nested list of id induction_v and op
def SwAlgorithm( inputList , ReportedNodes , Visited, pOutputList):
    
    
    ReportedNodesnext=[]
    
    for item in inputList:
        for node in item:
            removeIndex = ReportedNodes.index(item[0])
            ReportedNodes.pop(removeIndex)

            OutputList = inputList

            if node[2] == 'phi':
                #helper function parent
                for parnetNode in parentNodes(parentBB(item)):
                    if not parnetNode in Visited:
                        OutputList.append(parnetNode)
                        ReportedNodesnext.append(node)
            
            else:

                for parentNode in parnetNodes(thisBB(item)):
                    if parentNode not in Visited:
                        OutputList.append([parentNode)
                        ReportedNodesnext.append(node)

    pOutputListnext = []
    pOutputListnext = OutputList
    Visited.append(OutputList) #keeps stacking up

    if (OutputList == pOutputList):
        for item in OutputList:
            if item[2] == 'fun' or 'clo':
                newinputList.append(item.nodes)
            SwAlgorithm(item.nodes , ReportedNodes , Visited, pOutputList)

            else: sys.exit


    return OutputList, pOutputListnext, ReportedNodesnext, Visited


