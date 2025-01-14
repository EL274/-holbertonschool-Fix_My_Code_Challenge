###
#
# Sort integer arguments (ascending)
#
###

result = []
ARGV.each do |arg|
    # Skip if not integer
    next unless arg.match(/^-?[0-9]+$/)

    # Convert to integer
    i_arg = arg.to_i

    # Insert at the correct position
    inserted = false
    result.each_with_index do |val, index|
        if i_arg < val
            result.insert(index, i_arg)
            inserted = true
            break
        end
    end
    result << i_arg unless inserted
end

puts result
