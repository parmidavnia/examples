
input: id_list = op_list = List([node_id],[i_0,i_1,...]) , BB_Dependence_Graph
// op_list= list of the nodes givne as input to the algorithm, for first tun op_list={store_ID[], br_ID[], ret_ID, carry_dep[]}. for other runs, it is the list of nodes
//and iterations that the hardware has dumped as a trace.
//the dependence graph has the information of dependence between nodes and basic blocks, and loop carried dependences.


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
        if node[i][j] in Single run BB:
            if (node[i][j].type == phi){
                if (node[i][j].mask is correct) {
                    output_list.append(parent_nodes(parent BB))
                    saved_faulty_nodes.append(node[i][j])
                }

                else print (node[i][j].mask is incorrect)
            }
            
            //for other nodes
            else{
                output_list.append(parent_nodes(this BB))
                saved_faulty_nodes.append(node[i][j])
            }

    }
}

