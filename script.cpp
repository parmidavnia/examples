
input: id_list = id_list = List([node_id,i_0,i_1,...]) , BB_Dependence_Graph
definition: livenodes(BB[n]) = store nodes in that basic block, and nodes generating values on the output edges of that BB, either passing to other basic blocks or
being a carried dependency.
// for first run, node_id = {store_ID[], br_ID[], ret_ID} and for all iterations
//parent in a loop means one iteration back or last iteration if from outside
// this means the same iteration of the BB 

//removing any correctly behaving node and iteration from the list
// for each node id and all of its iterations.
for (i in id_list.node_id){
    for (j in id_list.iterations[i]){
        if (sw.node[i][j] == hw.node[i][j])
            remove j from list
        }
    if (any node_id left without any iterations) remove node_id
}
//the list will be a list of faulty node_ids and the iteration they behaved faulty in.



for (i in id_list.node_id){
    for (j in id_list.iterations[i]){
        if (node[i][j].type == phi){
            if (node[i][j].mask is correct) output_list.append(livenodes(parent BB))
            else print (node[i][j].mask is incorrect)
        }
        
        //for other nodes
        else{
            output_list.append(nodes(this BB))
        }
    
    }
}
