
For purpose of debuging we extract each top-level loop into its own new function and hence we look at nested loops as multiple function call. With this technique we localize each loop iteration interval and we debug each loop independent from the rest of the function.
    While we extract the loop we preserver the data and memory dependencies.


//Function the focus function
//report nodes: list of buggy nodes. The list at initial step is empty and we gradually feel the list.
Start Algorithm(Function, report_nodes):


input: id_list = op_list = List([node_id],[i_0,i_1,...]) , BB_Dependence_Graph
// op_list=  is the list of nodes
//and iterations that the hardware has dumped as a trace.
//the dependence graph has the information of dependence between nodes and basic blocks, and loop carried dependences.
output: output_list, saved_faulty_nodes //output given to the hw interface, and saved faulty nodes presented to the user


helper definitions: 
    livenodes(BB[n]) = store nodes in that basic block, and nodes generating values on the output edges of that BB, either passing to other basic blocks or
    being a carried dependency.
    parent_nodes(BB[n]) = nodes of which their output a certain node depends upon. this definition has to be given the scope of basic block we want to limit the nodes to.
    this BB = This basic block 
    parent BB = parent basic block
    saved_faulty_nodes = a list of the nodes that 
//the saved faulty nodes list will be a list of faulty node_ids and the iteration they behaved faulty in. this list will update in each run and at the end 
//it should contain the locations of the root bugs.

//step 1: update the faulty list: as we are in the next run, the parent nodes of the previous run's faulty nodes are being traced and guarded. if the last run's faulty
//node does not appear in the input list again, it means that by guarding it's parent the node started behaving correctly, meaning it was a problem with the inputs 
//so the node is removed from faulty node list.
for node in saved_faulty_nodes:
    if node[i][j] not found in op_list:
        remove from saved_faulty_nodes


//step 2:  to update the faulty list and the output list
output_list = op_list

for (i in op_list.node_id){
    for (j in op_list.iterations[i]){
            if (node[i][j].type == phi){
                if (node[i][j].mask is correct) {
                    for parent_node in parent_nodes(parent BB)
                    if parent_node not in visited:
                        output_list.append(parent_node)
                        saved_faulty_nodes.append(node[i][j])
                        if output_list.isChanged()
                            continue
                        else
                            terminate
                }

                else print (node[i][j].mask is incorrect)
            }
            
            //for other nodes
            else{
                for parent_node in parent_nodes(this BB)
                    if parent_node not in visited:
                        output_list.append(parent_node)
                saved_faulty_nodes.append(node[i][j])
                if output_list.isChanged()
                    continue
                else
                    Jump to step 5
            }

    }
}

visited.append(output_list)
Repeat step 4
    

Step 5:
//We call start_algorithm function recursively on each function call/loops and append buggy nodes to report_nodes list
//the algorithm finishes when we visited all of the call graph of the parent function.
//Since the HLS framework doesn't supporrt recursive calls, then the call graph would be tree and we don't need to be
//worry about recursion.
for node in output_list:
    if node.type is (Function or Clousure)
         Start_algoirthm(node, report_nodes)
    else
       report_nodes.append(node)
        
        
return report_nodes;

