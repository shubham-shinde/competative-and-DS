tests = [
	[[1, 2], [1, 3], [2, 3]],
	[[1, 2], [3, 1], [2, 3]],
	[[1, 2], [2, 3], [3, 4], [4, 1], [1, 5]],
	[[2, 1], [3, 1], [4, 2], [1, 4]],
	[[5, 2], [5, 1], [3, 1], [3, 4], [3, 5]],
	[[1, 2], [2, 1], [2, 3], [3, 4]]
]

function getParent(graph, n) {
	let parent_set = {}
	for (let node = 1; node <= n; node++) {
		parent_set[node] = 0
	}
	for (let node = 1; node <= n; node++) {
		if (graph[node] == undefined) continue
		for (let child of graph[node]) {
			parent_set[child]++
		}
	}
	let incoming_nodes = {
		0: [],
		1: [],
		2: []
	}
	for (let node of Object.keys(parent_set)) {
		incoming_nodes[parent_set[node]].push(Number(node))
	}
	return incoming_nodes
}

function visitedNodes(graph, root) {
	let visited_nodes = []
	let dfs = (parent) => {
		visited_nodes.push(parent)
		for (let child of (graph[parent] || [])) {
			dfs(child)
		}
	}
	dfs(root)
	return visited_nodes.length
}

function findEdge(edges) {
	let graph = {}
	for (let [s, e] of edges) {
		if (graph[s]) graph[s].push(e)
		else graph[s] = [e]
	}
	obj_graph = {}
	for (let n of Object.keys(graph)) {
		obj_graph[n] = graph[n].reduce((v, c) => ({...v, [c]: true}), {})
	}
	let parents = getParent(graph, edges.length)
	if (parents[0].length === 1) {
		for (let edge = edges.length - 1; edge >= 0; edge--) {
			if (edges[edge][1] === parents[2][0]) {
				graph[edges[edge][0]] = graph[edges[edge][0]].filter((e) => e !== edges[edge][1])
				if (visitedNodes(graph, parents[0][0]) == edges.length) {
					return edges[edge]
				}
				graph[edges[edge][0]].push(edges[edge][1])
			}
		}
	} else {
		for (let edge = edges.length - 1; edge >= 0; edge--) {
			if (parents[1].indexOf(edges[edge][1]) >= 0) {
				graph[edges[edge][0]] = graph[edges[edge][0]].filter((e) => e !== edges[edge][1])
				if (visitedNodes(graph, edges[edge][1]) == edges.length) {
					return edges[edge]
				}
				graph[edges[edge][0]].push(edges[edge][1])
			}
		}
	}
	return null
}

for (let i of tests) {
	console.log(findEdge(i))
}
